#include <windows.h>
#include <exdisp.h>

static GUID g_CLSID_InternetExplorer = { 0x0002DF01, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 };
static GUID g_IID_IWebBrowser2 = { 0xD30C1661, 0xCDAF, 0x11D0, 0x8A, 0x3E, 0x00, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E };

int main(void)
{
	IWebBrowser2* pBrowser;
	CoInitialize(NULL);
	CoCreateInstance(&g_CLSID_InternetExplorer, NULL, CLSCTX_LOCAL_SERVER, &g_IID_IWebBrowser2, (LPVOID*)&pBrowser);
	pBrowser->lpVtbl->put_Visible(pBrowser, VARIANT_TRUE);
	pBrowser->lpVtbl->Release(pBrowser);
	CoUninitialize();
	return 0;
}
