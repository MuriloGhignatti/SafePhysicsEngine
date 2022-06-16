
#include "../PluginManager/PluginHandle.h"

int main(int argc, char* argv[])
{
    PluginHandle myPluginHandle("test.dll");
    myPluginHandle.load()->onLoad();
    return 0;
}
