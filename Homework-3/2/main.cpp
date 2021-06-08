#include <iostream>
#include <vector>
#include "Folder.h"
#include "MusicFile.h"
#include "File.h"
#include "Image.h"
#include "FileSystem.h"

using namespace std;

int main()
{
	vector<MainFolder*> list;

	Image A("img", 12, "23.02.2001", 1000, ".jp", "Samsung G5", "1000", "1562");

	Image B("img1", 13, "20.02.2001", 100, ".jpg", "iphone", "2500", "2502");

	cout << "Print image information: " << endl;
	Image C("img2", 2, "16.23.2300", 1000, ".pgn", "Samsung G7", "1000", "1562");

	cout << endl;

	MainFolder* Test = &A;
//	Test->Print();
	list.push_back(Test);

	MainFolder* Test1 = &B;
//	Test->Print();
	list.push_back(Test1);

	MainFolder* Test2 = &C;
//	Test->Print();
	list.push_back(Test2);

	Folder folder("fol", "12.03.1999", list);
	Folder folder2("fol2", "12.03.1999", list);
	folder.Add(folder2);
	folder.Add(A);
	folder.Remove("fol2");
	folder.Print();

    cout << "Search file in the list and print it" << endl;
    FileSystem FS(list);
    FS.search("img");

	system("pause");
	return 0;
}
