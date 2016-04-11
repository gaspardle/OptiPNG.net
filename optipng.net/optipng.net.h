// optipng.net.h

#pragma once
#include "optipng.h"

using namespace System;

namespace OptiPNGNet {

    public ref class OptiPNGOptions
    {
    protected:
      

    public:
        opng_options* options;
        OptiPNGOptions();
        !OptiPNGOptions();
        ~OptiPNGOptions();       
       
        /// <summary>
        /// Select the optimization level.
        /// </summary>   
        property int OptimizationLevel {
            int get() {
                return options->optim_level;
            }
            void set(int value) {
                options->optim_level = value;
            }        
        }

        /// <summary>
        /// Select the interlace type 
        /// If the interlace type 0 is selected, the output image shall be non-interlaced (i.e. progressivescanned).
        /// If the interlace type 1 is selected, the output image shall be interlaced using the Adam7 method.
        /// </summary>   
        property bool Interlace {
            bool get() {
                return options->interlace != 1;
            }
            void set(bool value) {
                options->interlace = 1;
            }
        }

        /// <summary>
        /// Enforce writing of a new output file.
        /// This option overrides the program’s decision not to write such file,        /// e.g. when the PNG input is digitally signed (using dSIG), or when the         /// PNG output becomes larger than the PNG input.
        /// </summary>        
        property bool Force {
            bool get() {
                return options->force != 1;
            }
            void set(bool value) {
                options->force = 1;
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
