#include <list>
#include <string>

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　表示処理
//////////////////////////////////////////////////////////////////////////////////////////////////

void ShowStation(const std::list<const char*>& list, char buffer[]) {
	uint32_t index = 1;
	for (std::list<const char*>::const_iterator it = list.begin(); it != list.end(); ++it) {
		const char* no = "JY";
		std::snprintf(buffer, sizeof(buffer), "%s%d", no, index);
		printf(buffer);
		if (index <= 9) {
			printf("   ");
		} else {
			printf("  ");
		}

		printf((*it));
		printf("\n");
		++index;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　追加処理
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertList(std::list<const char*>& list, const char* insertName, const char* frontName, const char* backName) {
	for (std::list<const char*>::const_iterator it = list.begin(); it != list.end(); ++it) {
		std::list<const char*>::const_iterator next = std::next(it);
		if ((*it) == frontName && (*next) == backName) {
			next = list.insert(next, insertName);
			++it;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　main処理
//////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

	std::list<const char*> stations_1970;
	std::list<const char*> stations_2019;
	std::list<const char*> stations_2022;

	// 1970年代を作ってそこに追加された駅を挿入していく	
	stations_1970.emplace_back("Tokyo");
	stations_1970.emplace_back("Kanda");
	stations_1970.emplace_back("Akihabara");
	stations_1970.emplace_back("Okachimachi");
	stations_1970.emplace_back("Ueno");
	stations_1970.emplace_back("Uguisudani");
	stations_1970.emplace_back("Nippori");
	stations_1970.emplace_back("Tabata");
	stations_1970.emplace_back("Komagome");
	stations_1970.emplace_back("Sugamo");
	stations_1970.emplace_back("Otsuka");
	stations_1970.emplace_back("Ikebukuro");
	stations_1970.emplace_back("Mejiro");
	stations_1970.emplace_back("Takadanobaba");
	stations_1970.emplace_back("Shin-Okubo");
	stations_1970.emplace_back("Shinjuku");
	stations_1970.emplace_back("Yoyogi");
	stations_1970.emplace_back("Harajuku");
	stations_1970.emplace_back("Shibuya");
	stations_1970.emplace_back("Ebisu");
	stations_1970.emplace_back("Meguro");
	stations_1970.emplace_back("Gotanda");
	stations_1970.emplace_back("Osaki");
	stations_1970.emplace_back("Shinagawa");
	stations_1970.emplace_back("Tamachi");
	stations_1970.emplace_back("Hamamatsucho");
	stations_1970.emplace_back("Shimbashi");
	stations_1970.emplace_back("Yurakucho");

	// 要素の追加
	stations_2019 = stations_1970;
	InsertList(stations_2019, "Nishi-Nippori", "Nippori", "Tabata");
	stations_2022 = stations_2019;
	InsertList(stations_2022, "Takanawa-Gateway", "Shinagawa", "Tamachi");

	// 表示
	char buffer[50];
	printf("\n--------------------------- 1970 ---------------------------\n");
	ShowStation(stations_1970, buffer);
	printf("\n--------------------------- 2019 ---------------------------\n");
	ShowStation(stations_2019, buffer);
	printf("\n--------------------------- 2022 ---------------------------\n");
	ShowStation(stations_2022, buffer);
	

	return 0;
}