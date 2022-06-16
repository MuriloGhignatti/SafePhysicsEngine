
#include "../PluginManager/PluginHandle.h"

int main(int argc, char* argv[])
{
    PluginHandle myPluginHandle("PluginTest.dll");
    myPluginHandle.load()->onLoad();
    return 0;
}
