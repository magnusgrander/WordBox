#include <iostream>
#include "WordBox.h"

int main()
{
    WordBox w,wb,wn;        
	
	wb.textLength(40);
	wb.addContent( L"Comparison of Linux Distributions" );
	wb.newRow();
	wb.print();
	
	w.textLength(14);	
    w.addContent( L"Beginners" );
    w.addContent( L"Advanced " );
    w.addContent( L"Experts" );
    w.newRow();
    
    w.addContent( L"Ubuntu / Kubuntu" );
    w.addContent( L"openSüSE" );
    w.addContent( L"Mageia" );
    w.newRow();

    w.addContent( L"Debian" );
    w.addContent( L"RHEL" );
    w.addContent( L"Arch" );
    w.newRow();

    w.addContent( L"Feodora" );
    w.addContent( L"Zorin" );
    w.addContent( L"Slackware" );
    w.newRow();
    
    w.addContent( L"SLAX" );
    w.addContent( L"KaOS" );
    w.addContent( L"Chimera linux" );
    w.newRow();    
      
    w.setAlign(0, false);
    w.print();
        
    wn.addContent( L"12.24" );
    wn.addContent( L"1323" );
    wn.addContent( L"43443" );
    wn.newRow();
    
    wn.addContent( L"200.000" );
    wn.addContent( L"25" );
    wn.addContent( L"78.90" );
    wn.newRow();
    
    wn.toggleRuler();
    wn.setAlign(1, false);
    wn.print();
   
    return 0;
}
