#include "Stdafx.h"
#include "SeungChan.h"


HRESULT SeungChan::init(void)
{
    
    return S_OK;
}

void SeungChan::release(void)
{

}

void SeungChan::update(void)
{
    
}

void SeungChan::render(void)
{
    namePrint();
}

void SeungChan::namePrint(void)
{
    char test[100];
    int x = 0;
    int y = (WINSIZE_Y/2) -5;
    for (int i = 0; i < 10; i++)
    {
        wsprintf(test, "³ë½ÂÂù");
        TextOut(getMemDC(), x, y, test, strlen(test));
        x += 30;
        y -= 22;
    }
}
