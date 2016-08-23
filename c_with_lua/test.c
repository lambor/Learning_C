#include<stdio.h>
#include"lua.h"
#include"lauxlib.h"
#include"lualib.h"

static int ltest(lua_State *L) {
    lua_getfield(L, lua_upvalueindex(1), "a");
    printf("%d\n",lua_tointeger(L, -1));
    return 1;
}

static int luaTest(lua_State *L) {
    luaL_Reg l[] =
    {
        {"test",ltest},
        {NULL,NULL},
    };
    luaL_newlibtable(L, l);
    lua_pushvalue(L, -1);
    luaL_setfuncs(L, l, 1);
    return 1;
}

int main()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_requiref(L, "LuaTest", luaTest, 0);
    luaL_dofile(L, "a.lua");
    return 0;
}