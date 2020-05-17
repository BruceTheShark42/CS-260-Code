#include <iostream>
#include "WebTable.h"

using namespace std;

int main() {
	WebTable table;
	
	Website site("https://www.google.com/", "Stupid summary", "Ugly review", 5);
	Website site2("https://www.images.google.com/", "Stupid summary 342222", "Ugly review 2", 1);
	Website site3("https://www.youtube.com/", "Stupid summary 465", "Ugly review 33", 3);
	table.add("Google", site);
	table.add("Google", site2);
	table.add("YouTube", site3);
	
	cout << "\n-----------------\n";
	size_t total = 0;
	Website *sites = table.get("Google", total);
	for (size_t i = 0; i < total; ++i)
		cout << sites[i];
	delete[] sites;
	cout << "\n-----------------\n";
	
	cout << table;
	
	site3.setRating(1);
	site3.setReview("oh how you are dead - not shakespere or however you spell his name");
	table.set("YouTube", site3);
	cout << "\n-----------------\n";
	
	cout << table;
	cout << "\n-----------------\n";
	table.cull();
	cout << table;
	
	return 0;
}
