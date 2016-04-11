// This is the main DLL file.

#include "stdafx.h"
#include <msclr\marshal.h>
#include "optipng.net.h"


static void
app_printf(const char *fmt, ...)
{
}

static void
app_print_cntrl(int cntrl_code)
{
}

static void
app_progress(unsigned long current_step, unsigned long total_steps)
{
}

void panic(const char *msg)
{
    throw gcnew System::Exception(gcnew String(msg));
}

OptiPNGNet::OptiPNG::OptiPNG(OptiPNGOptions^ options)
{
    this->options = options;

    struct opng_ui ui;
 
    /*Initialize the optimization engine. */
    ui.printf_fn = app_printf;
    ui.print_cntrl_fn = app_print_cntrl;
    ui.progress_fn = app_progress;
    ui.panic_fn = panic;

    if (opng_initialize(options->options, &ui) != 0) {
        panic("Can't initialize optimization engine");
    }

}


System::Boolean OptiPNGNet::OptiPNG::ProcessFile(System::String^ infilename, System::String^ outfilename) {

    msclr::interop::marshal_context context;
    const char* cstring_infilename = context.marshal_as<const char*>(infilename);
    const char* cstring_outfilename = context.marshal_as<const char*>(outfilename);

    options->options->out_name = cstring_outfilename;

    int result = opng_optimize(cstring_infilename);
    if (result == 0) {
        return true;
    }
    else {
        return false;
    }
}


OptiPNGNet::OptiPNGOptions::OptiPNGOptions()
{
    options = new opng_options();
    options->optim_level = -1;
    options->interlace = -1;
}

OptiPNGNet::OptiPNGOptions::!OptiPNGOptions()
{
   delete options;
}

OptiPNGNet::OptiPNGOptions::~OptiPNGOptions()
{

}

