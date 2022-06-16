
#include "SafeModuleManager.h"

int main(int argc, char* argv[])
{
    SafeModuleManager myPluginHandle("test.dll");
    myPluginHandle.load()->onLoad();
    return 0;
}
