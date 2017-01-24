#include "Skype.h"

	Skype::Skype() {
		CoInitialize(NULL);
		_skype.CreateInstance(__uuidof(SKYPE4COMLib::Skype));

		if (!_skype->Client->IsRunning) {
			_skype->Client->Start(VARIANT_TRUE, VARIANT_TRUE);
		}
		_skype->Attach(5, VARIANT_TRUE);
	}

	Skype::~Skype() {
		_skype = NULL;
		CoUninitialize();
	}

	void Skype::sendMessage(const std::string& recipiant, const std::string& message) {
		SKYPE4COMLib::IChatMessage* message_handle = _skype->SendMessage(recipiant.c_str(), message.c_str());
	}

	void Skype::getFriendList(std::vector<std::string>& friend_list) {
		SKYPE4COMLib::IUserCollectionPtr friends = _skype->GetFriends();
		for (auto i = 1; i <= friends->GetCount(); ++i) {
			friend_list.push_back((std::string)friends->GetItem(i)->GetHandle());
		}
	}

	int Skype::getFriendIndex(const std::string& name) {
		int index = -1;
		std::vector<std::string> friends_list;
		getFriendList(friends_list);
		for (auto i = 0; i < friends_list.size(); ++i) {
			if (friends_list[i] == name) index = i;
		}
		return index;
	}
