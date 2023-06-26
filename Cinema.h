#pragma once
class Cinema
{
private:
	string pathImg;
	float rating;
	bool subscription;
	bool top10;
	vector<string> category;

	map<string, string> getFields(string str) {
		map<string, string> array;

		cout << str.length() << endl;
		for (int i = 0,k=0; i < str.length(); i++) {
			if (str[i] == '"') {
				string key = "";
				//поиск ключа
				for (int j = i + 1; str[j] != '"'; j++) {
					key += str[j];
				}
				//поиск разделителя :
				for (int j = i + key.length();j<str.length(); j++) {
					if (str[j] == ':') {
						k = j + 1;
						break;
					}
				}
				//начало значений
				for (int j = k; j < str.length(); j++) {
					if (str[j] != ' ') {
						k = j;
						break;
					}
				}
				//получение value
				bool flagArr = (str[k]=='[');
				bool flagStr;
				if (str[k] == '"') {
					k++;
					flagStr = true;
				}
				else flagStr = false;
				string value = "";
				for (int j = k; j < str.length(); j++) {
					if (flagArr) {
						value += str[j];
						if (str[j] == ']')
						{
							k = j;
							break;

						}
					}
					else if(flagStr) {
						value += str[j];
						if (str[j+1] == '"') {
							k = j+1;
							break;

						}
					}
					else {
						if (str[j] == ',') {
							k = j;
							break;
						}
						else value += str[j];
					}
				}

				array[key] = value;
				i = k;
			}
			
		}
		return array;
	}
public:
	Cinema(string str) {
		map<string, string> array = getFields(str);
		for (const auto& el : array) {
			cout << el.first << ": " << el.second << endl;
		}
	}
	void showInfo() {
		cout <<"path: "<< pathImg << endl;
		cout <<"rating: "<< rating << endl;
		cout << "subs: " << subscription << endl;
		cout << "top10: " << top10 << endl;
		cout << "category: ";
		for (auto el : category) {
			cout << el << " ";
		}
		cout << endl;
	}
};

