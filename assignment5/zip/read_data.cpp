#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream in_recur("results_recur.dat");
	ifstream in_closed("results_closed.dat");
	ifstream in_bottom_up("results_bottom_up.dat");
	ifstream in_matrix("results_matrix.dat");

	ofstream output("concat_results.dat");
	double data1, data2, data3, data4;
	int index1, index2, index3;
	int index = 0;
	while(index <= 24) {
		in_recur >> index1 >> data1;
		in_closed >> index2 >> data2;

		in_bottom_up >> index3 >> data3;

		in_matrix >> index >> data4;
		output << index << " " << data1 << " " << data2 << " " << data3 << " " << data4 << endl;
	}

	in_recur.close();
	in_closed.close();
	in_bottom_up.close();
	in_matrix.close();
	output.close();

	return 0;
}
