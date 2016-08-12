/**
* ############################################################
* # THIS IS A TEST FILE - IT DOES NOT DEMONSTRATE FULL USAGE #
* # OF THE ENGINE. IT ONLY DEMONSTRATES NEW ITEMS THAT ARE   #
* # BEING TESTED BY THE CR TEAM.                             #
* #                                                          #
* #          MAY THE CODING GODS BLESS THIS CODE!            #
* ############################################################
*/

#include <assert.h>
#include <stddef.h>
#include <new>
#include <iostream>

#include "CRCore.hpp"
#include "TestApp.hpp"

int main(int argc, char* argv[])
{
    // Default exit code
    int exitCode = CRE::STATUS_OK;

    // Create our app
    CRE::App * testApp = new(std::nothrow) TestApp("Testing", 512, 512);
    assert(NULL != testApp and "main() can't create application");

    //testApp->set_max_updates(1);

    // Execute the application
    exitCode = testApp->run();

    delete testApp;

    testApp = NULL;

    return exitCode;
}
