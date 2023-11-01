#include "pch.h"
#include "NoteToIndex.h"
#include <map>
#include <string>

using namespace std;

static int g_initialized = false;
static map<wstring, int> g_name2index;

double NoteToIndex(const WCHAR* name)
{
    if (!g_initialized)
    {
        int g = sizeof(indexes);
        for (int i = 0; i < 88; i++)
        {
            g_name2index[indexes[i].name] = indexes[i].index;
        }

        g_initialized = true;
    }

    map<wstring, int>::iterator f = g_name2index.find(name);
    if (f == g_name2index.end())
        return 0;

    return f->second;
}