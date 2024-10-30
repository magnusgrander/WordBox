Visualize your data like this:

+-----------------------------------+
| Comparison of Linux Distributions |
+-----------------------------------+
+-----------------+-----------+---------------+
|       Beginners | Advanced  | Experts       |
+-----------------+-----------+---------------+
| Ubuntu / Kubu...| openSüSE  | Mageia        |
|          Debian | RHEL      | Arch          |
|         Feodora | Zorin     | Slackware     |
|            SLAX | KaOS      | Chimera linux |
+-----------------+-----------+---------------+
| 12.24   | 1323 | 43443 |
| 200.000 |   25 | 78.90 |


Transform your data into captivating visuals that will make an impact. Use the free WordBox class print values in rows and columns and make it easy to compare and analyze data at a glance. Present raw statistics to predict market performance or simply display non-quantitative information readers can quickly look up. Make a table with ease. Export your data from any medium and visual the data with classic table borders.

Its easy !

Include the WordBox header and initiate the object class.
#include "WordBox.h"
WordBox w

Optional set the max length of the text inside the table.
The standard is set too 20 characters. If the text is longer
then that then the text is cut off and "..." is shown instead.

w.textLength(14);

The class can handle extended characters by default.
So it should be no problem showing the text in any language.

Add content to the table and upload it to the class.

w.textLength(14);	
w.addContent( L"Beginners" );
w.addContent( L"Advanced " );
w.addContent( L"Experts" );
w.newRow();

By default all text is aligned to the left. If you want to
sidestep that rule you can bypass that.

w.setAlign(0, false);

This sets the first table alignment to the right.

If you don't want to show the entire ruler you can toggle that to

w.toggleRuler();

When every data is set and everything is ready then it is just:

w.print();

and that will print out the result in nice looking tables with headers.
The demo file will show of some examples on how to use it. 

Please feel free to give feedback and suggestions for more functions. 

Greetings;
Magnus Grander





























