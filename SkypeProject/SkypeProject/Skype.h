#import "C:\Program Files (x86)\Common Files\Skype\Skype4COM.dll"
using namespace SKYPE4COMLib;

#include <string>
#include <vector>
using namespace std;

class Skype
{
private:
	ISkypePtr _skype;

public:
	Skype();

	~Skype();

	void sendMessage(const std::string& recipiant, const std::string& message);

	void getFriendList(std::vector<std::string>& friend_list);

	int getFriendIndex(const std::string& name);
};