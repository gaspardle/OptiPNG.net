OptiPNG.Net
============

Use OptiPNG from .Net without any others external dependencies.

> OptiPNG is a PNG optimizer that recompresses image files to a smaller size, without losing any information.

> [OptiPNG: Advanced PNG Optimizer](http://optipng.sourceforge.net/)

Not threadsafe

Usage
---------------------
```C#
var options = new OptiPNGOptions() { OptimizationLevel = 7 };
var optipng = new OptiPNG(options);

var result = optipng.ProcessFile("myfile.png", "target.png");
```

TODO
---------------------
 - error handling
 - nuget package