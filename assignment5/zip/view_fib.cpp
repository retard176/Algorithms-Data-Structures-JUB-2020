#include <iostream>
#include <fstream>

using namespace std;

int main() {

	int index = 0;
	double data1, data2, data3, data4;

	ifstream in("concat_results.dat");
	cout << "Index Naive Closed Bottom Matrix" << endl;
	while(index <= 24) {
		in >> index >> data1 >> data2 >> data3 >> data4;
		cout << index << " " << data1 << " " << data2 << " " << data3;
                cout << " " << data4 << endl;
		index++;
	}
	
	return 0;
}
