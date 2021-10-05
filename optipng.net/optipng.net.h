// optipng.net.h

#pragma once
#include "optipng.h"

using namespace System;

namespace OptiPNGNet {

    public ref class OptiPNGOptions
    {
    internal:
        opng_options* options_internal;

    public:
        
        OptiPNGOptions();
        !OptiPNGOptions();
        ~OptiPNGOptions();       
       
        /// <summary>
        /// Select the optimization level.
        /// </summary>   
        property int OptimizationLevel {
            int get() {
                return options_internal->optim_level;
            }
            void set(int value) {
                options_internal->optim_level = value;
            }        
        }

        /// <summary>
        /// Select the interlace type 
        /// If the interlace type 0 is selected, the output image shall be non-interlaced (i.e. progressivescanned).
        /// If the interlace type 1 is selected, the output image shall be interlaced using the Adam7 method.
        /// </summary>   
        property bool Interlace {
            bool get() {
                return options_internal->interlace != 1;
            }
            void set(bool value) {
                options_internal->interlace = value;
            }
        }

        /// <summary>
        /// Enforce writing of a new output file.
        /// This option overrides the program’s decision not to write such file,
        /// e.g. when the PNG input is digitally signed (using dSIG), or when the 
        /// PNG output becomes larger than the PNG input.
        /// </summary>        
        property bool Force {
            bool get() {
                return options_internal->force != 1;
            }
            void set(bool value) {
                options_internal->force = value;
            }
        }
        property bool Overwrite {
            bool get() {
                return options_internal->clobber != 1;
            }
            void set(bool value) {
                options_internal->clobber = value;
            }
        }
        property bool Simulate {
            bool get() {
                return options_internal->simulate != 1;
            }
            void set(bool value) {
                options_internal->simulate = value;
            }
        }
        property bool Strip {
            bool get() {
                return options_internal->strip_all != 1;
            }
            void set(bool value) {
                options_internal->strip_all = value;
            }
        }

        property bool Snip {
            bool get() {
                return options_internal->snip != 1;
            }
            void set(bool value) {
                options_internal->snip = value;
            }
        }

        property bool Fix {
            bool get() {
                return options_internal->fix != 1;
            }
            void set(bool value) {
                options_internal->fix = value;
            }
        }
    };

	public ref class OptiPNG
	{
        private: 
            OptiPNGOptions^ options;
          
        public:
            OptiPNG(OptiPNGOptions^ options);
            System::Boolean ProcessFile(System::String^ infilename, System::String^ filename);
	};


}
