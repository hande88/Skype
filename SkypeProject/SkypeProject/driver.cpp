#import "C:\Program Files (x86)\Common Files\Skype\Skype4COM.dll"
using namespace SKYPE4COMLib;

int main()
{
	CoInitialize(NULL);
	ISkypePtr pSkype;
	pSkype.CreateInstance(__uuidof(Skype));

	if (!pSkype->Client->IsRunning) {
		pSkype->Client->Start(VARIANT_TRUE, VARIANT_TRUE);
	}
	pSkype->Attach(5, VARIANT_TRUE);

	IUserCollectionPtr friends = pSkype->GetFriends();
	long friend_count = friends->GetCount();

	pSkype = NULL;
	CoUninitialize();
}