// This is the main DLL file.

#include "stdafx.h"
#include <msclr\marshal.h>
#include "optipng.net.h"
#include <iostream>


static void app_printf(const char *fmt, ...)
{
   //va_list arg_ptr;

   //if (fmt[0] == 0)       
   //    return;

   //va_start(arg_ptr, fmt);
   //vfprintf(stdout, fmt, arg_ptr);
   //va_end(arg_ptr);
}

static void app_print_cntrl(int cntrl_code)
{
    //Console::WriteLine("app_print_cntrl {0}", cntrl_code);
}

static void app_progress(unsigned long current_step, unsigned long total_steps)
{    
    //Console::WriteLine("  (t:{0}) [{1} of {2}]", System::Threading::Thread::CurrentThread->ManagedThreadId, current_step, total_steps);
}

static void panic(const char *msg)
{
    throw gcnew System::Exception(gcnew String(msg));
}

OptiPNGNet::OptiPNG::OptiPNG(OptiPNGOptions^ options)
{
    this->options = options;
}

System::Boolean OptiPNGNet::OptiPNG::ProcessFile(System::String^ infilename, System::String^ outfilename) {

    msclr::interop::marshal_context context;
    const char* cstring_infilename = context.marshal_as<const char*>(infilename);
    const char* cstring_outfilename = context.marshal_as<const char*>(outfilename);

    options->options_internal->out_name = cstring_outfilename;
    struct opng_ui ui;
    ui.printf_fn = app_printf;
    ui.print_cntrl_fn = app_print_cntrl;
    ui.progress_fn = app_progress;
    ui.panic_fn = panic;
    if (opng_initialize(options->options_internal, &ui) != 0) {
        panic("Can't initialize optimization engine");
    }
    
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
    options_internal = new opng_options();
    options_internal->optim_level = -1;
    options_internal->interlace = -1;
}

OptiPNGNet::OptiPNGOptions::!OptiPNGOptions()
{
   delete options_internal;
}

OptiPNGNet::OptiPNGOptions::~OptiPNGOptions()
{

}

