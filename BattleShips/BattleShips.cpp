// AmiralYeni.cpp: Konsol uygulamasýnýn giriþ noktasýný tanýmlar.
//

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;
int userboard[11][11] = { {0,7,2,3,4,5,6,7,8,9,10},{7},{2},{3},{4},{5},{6},{7},{8},{9},{10} },
compboard[11][11] = { { 0,7,2,3,4,5,6,7,8,9,10 },{ 7 },{ 2 },{ 3 },{ 4 },{ 5 },{ 6 },{ 7 },{ 8 },{ 9 },{ 10 } };
int shipsizes[5] = { 5,4,3,3,2 }, ship, row, column, direction, shipisselected[5] = { 1,1,1,1,1 }, compship = 0, comprow, compcolumn, compdirection, compshootboard[11][11] = { { 0,1,2,3,4,5,6,7,8,9,10 },{ 1 },{ 2 },{ 3 },{ 4 },{ 5 },{ 6 },{ 7 },{ 8 },{ 9 },{ 10 } }, usershootrow, usershootcolumn, compshootrow, compshootcolumn, compshootedbefore[11][11] = {}, usershootedbefore[11][11] = {};
void selectcoordinate();
void enter();
void setship();
int  allsettedcheck();
int  crosscheck();
int  nextcheck();
int  fixcheck();
void setcompship();
void showuserboard();
void showcompboard();
void selectship();
void generatecompcoor();
void selectcompship();
void generatecompdirect();
int  compcrosscheck();
int  compnextcheck();
int  compfixcheck();
int  usershoot();
void selectshootcoor();
int  compshoot();
void generatecompshootcoor();
void showcompshootboard();
int  main()
{

	enter();

	return 0;

};

void enter() {

	//kullanýnýn gemileri girdiði yer 
	int islem, hatafix, hatacross, hatanext, isallselected;
	cout << "Press 1 to start : ";
	cin >> islem;
	if (islem == 1)
	{


		showuserboard();
		do
		{

			selectship();
			selectcoordinate();
			hatafix = fixcheck();
			hatacross = crosscheck();
			hatanext = nextcheck();
			if (hatacross == 0 && hatanext == 0 && hatafix == 0 && hatanext == 0)
			{
				setship();
				shipisselected[ship] = 0;
			}
			isallselected = allsettedcheck();
			showuserboard();
		} while (hatacross == 1 || hatanext == 1 || hatafix == 1 || isallselected == 1);

		cout << endl << "PLease Wait Computers Planting ..." << endl;

		//bilgisayarýn gemileri yerleþtirdiði kýsým 
		int  comphatafix, comphatacross, comphatanext;
		do
		{

			generatecompcoor();
			generatecompdirect();
			comphatafix = compfixcheck();
			comphatacross = compcrosscheck();
			comphatanext = compnextcheck();

			if (comphatacross == 0 && comphatanext == 0 && comphatafix == 0)
			{
				setcompship();
				selectcompship();
			}

		} while (comphatacross == 1 || comphatanext == 1 || comphatafix == 1 || compship < 5);

		//showcompboard();

		//atýþlar 


		int udestroy = 0, uhit, chit, compdestroy = 0;
		do
		{
			showuserboard();
			cout << endl << "User hitted " << compdestroy << " times" << endl;
			showcompshootboard();
			cout << endl << "Computer hitted " << udestroy << " times" << endl;
			selectshootcoor();
			uhit = usershoot();
			generatecompshootcoor();
			chit = compshoot();
			if (uhit == 1)
			{
				udestroy++;
			}

			if (chit == 1)
			{
				compdestroy++;
			}


		} while (udestroy < 17 && compdestroy < 17);

		if (udestroy == 17)
		{
			cout << endl << "!!!!!***** CONGRATULATIONS YOU WON :) *****!!!!!" << endl;
		}
		if (compdestroy == 17)
		{
			cout << endl << "!!!!!***** YOU LOSE :( *****!!!!!" << endl;
		}

	}

};
void showuserboard() {
	cout << endl << "User Board" << endl;
	for (size_t i = 0; i < 11; i++)
	{

		cout << setw(2);
		for (size_t j = 0; j < 11; j++)
		{
			cout << userboard[i][j] << " ";
		}
		cout << endl;
	}
	cout << "0=empty area ||1 =ships || 2 = hitted ships ||4 = missed area || " << endl;
};
void showcompboard() {
	cout << "Computer Board " << endl;
	for (size_t i = 0; i < 11; i++)
	{
		cout << setw(2);
		for (size_t j = 0; j < 11; j++)
		{
			cout << compboard[i][j] << " ";
		}
		cout << endl;
	}
	cout << "0=empty area || 1 =ships || 2 = hitted ships || 4 = missed shoots ||" << endl;
};
void setship() {


	switch (direction)
	{
	case 1: // up side 
		for (size_t i = 0; i < shipsizes[ship]; i++)
		{
			userboard[(row)-i][column] = 1;
		}
		break;
	case 2:// down side 
		for (size_t i = 0; i < shipsizes[ship]; i++)
		{
			userboard[(row)+i][column] = 1;
		}
		break;
	case 3://left side 

		for (size_t i = 0; i < shipsizes[ship]; i++)
		{
			userboard[row][column - i] = 1;
		}
		break;

	case 4:// right side 
		for (size_t i = 0; i < shipsizes[ship]; i++)
		{
			userboard[row][column + i] = 1;
		}
		break;
	default:
		break;
	}
};
void selectship() {
	cout << endl;
	int hata = 0, shiptemp;
	do
	{
		hata = 0;
		cout << "Please select a ship for planting  \n";
		cout << "(-)Ships      Size    How many " << endl;
		cout << "1-)Carrier    5     " << shipisselected[0] << endl;
		cout << "2-)BattleShip 4     " << shipisselected[1] << endl;
		cout << "3-)Cruiser    3     " << shipisselected[2] << endl;
		cout << "4-)Submarine  3     " << shipisselected[3] << endl;
		cout << "5-)Destroyer  2     " << shipisselected[4] << endl;
		cin >> shiptemp;

		if (shiptemp > 5 || shiptemp < 0)
		{
			cout << "Selected ship run out  !!";
			hata = 1;
		}

		else
		{

			if (shipisselected[shiptemp - 1] == 0)
			{
				cout << "This ship already selected before !!" << endl;
				hata = 1;
			}


		}

	} while (hata == 1);
	ship = shiptemp - 1;

};
void selectcoordinate() {
	int hata = 0, xcoortemp, ycoortemp, directiontemp;
	//coorrdinat girme
	do
	{
		hata = 0;
		cout << endl;
		cout << "Please enter row coordinate : " << endl;
		cin >> xcoortemp;
		cout << "Please enter column coordinate : " << endl;
		cin >> ycoortemp;
		if (xcoortemp <= 0 || xcoortemp > 10 || xcoortemp == 0)
		{
			hata = 1;
			cout << "Corrdinates must be btw 1-10 !!" << endl;
		}

		if (ycoortemp <= 0 || ycoortemp > 10)
		{

			hata = 1;
			cout << "Coordinate must be btw 1-10 !!" << endl;
		}

	} while (hata == 1);
	row = xcoortemp;
	column = ycoortemp;
	//yatay dikey yön seçme 
	do
	{
		hata = 0;
		cout << endl;
		cout << "Press 1 to Up positioning   " << endl << "     2 to Down positioning " << endl << "     3 to left positioning " << endl << "    4 to right positioning :" << endl;;
		cin >> directiontemp;

		if (directiontemp < 0 || directiontemp>4)
		{
			hata = 1;
			cout << "direction  must be  btw 0 and 4 !!" << endl;
		}
	} while (hata == 1);
	direction = directiontemp;


};
int  fixcheck() {

	int hata = 0;
	//sýgýyor mu diye kontrol 
	switch (direction)
	{
	case 1: // up side 
		if (shipsizes[ship] > row)
		{
			cout << "Selected ship is not fix for up !! ";
			hata = 1;
		}




		break;
	case 2:// down side 
		if (shipsizes[ship] > 11 - row)
		{

			cout << "Selected ship is not fix for down !! ";
			hata = 1;
		}

		break;
	case 3://left side 

		if (shipsizes[ship] > column)
		{

			cout << "Selected ship is not fix for left  !! ";
			hata = 1;
		}
		break;
	case 4:// right side 
		if (shipsizes[ship] > 11 - column)
		{
			cout << "Selected ship is not fix for right  !! ";
			hata = 1;
		}

		break;
	default:
		break;
	}
	return hata;


};
int  crosscheck() {
	int hata = 0;
	switch (direction)
	{
	case 1: // up side 
		for (size_t i = 0; i < shipsizes[ship]; i++)
		{
			if (userboard[(row)-i][column] == 1)
			{
				cout << "Ships are not be in same uniqe areas !!" << endl;
				hata = 1;
			}

		}
		break;
	case 2:// down side 
		for (size_t i = 0; i < shipsizes[ship]; i++)
		{
			if (userboard[(row)+i][column] == 1)
			{
				cout << "Ships are not be in same uniqe areas !!" << endl;
				hata = 1;
			}
		}
		break;
	case 3://left side 

		for (size_t i = 0; i < shipsizes[ship]; i++)
		{
			if (userboard[row][column - i] == 1)
			{
				cout << "Ships are not be in same uniqe areas !!" << endl;
				hata = 1;
			}
		}
		break;

	case 4:// right side 
		for (size_t i = 0; i < shipsizes[ship]; i++)
		{
			if (userboard[row][column + i] == 1)
			{

				cout << "Ships are not be in same uniqe areas !!" << endl;
				hata = 1;

			}
		}
		break;
	default:
		break;

	}
	return hata;
};
int  nextcheck() {
	int hata = 0;
	switch (direction)
	{
	case 1: // up side
	  // sol taraf degiyoru mu ? 
		for (size_t i = 0; i < shipsizes[ship] + 2; i++)
		{
			if (userboard[(row + 1) - i][column - 1] == 1)
			{
				cout << "A ship can not be next to other one : " << endl;
				hata = 1;
			}
			// sað taraf deðiyor mu ? 
		}
		for (size_t i = 0; i < shipsizes[ship] + 2; i++)
		{
			if (userboard[(row - 1) - i][column + 1] == 1)
			{
				cout << "A ship can not be next to other one : " << endl;
				hata = 1;
			}
		}
		// alt taraf deðiyor mu ?
		if (userboard[row + 1][column] == 1)
		{
			cout << "A ship can not be next to other one : " << endl;
			hata = 1;
		}
		//üst taraf degiyor mu ?
		if (userboard[row - shipsizes[ship]][column] == 1)
		{
			cout << "A ship can not be next to other one : " << endl;
			hata = 1;
		}
		break;
	case 2:// down side 
		//sol taraf deðiyor mu 
		for (size_t i = 0; i < shipsizes[ship] + 2; i++)
		{
			if (userboard[row - 1 + i][column - 1] == 1)
			{
				cout << "A ship can not be next to other one : " << endl;
				hata = 1;
			}
		}
		//sag taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[ship] + 2; i++)
		{
			if (userboard[row - 1 + i][column + 1] == 1)
			{
				cout << "A ship can not be next to other one : " << endl;
				hata = 1;
			}
		}
		//alt taraf degiyor mu 
		if (userboard[row + shipsizes[ship]][column] == 1)
		{
			cout << "A ship can not be next to other one : " << endl;
			hata = 1;
		}
		// üst taraf degiyor ku 
		if (userboard[row - 1][column] == 1)
		{
			cout << "A ship can not be next to other one : " << endl;
			hata = 1;
		}
		break;
	case 3://left side 
		//üst taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[ship] + 2; i++)
		{
			if (userboard[row - 1][column + 1 - i] == 1)
			{
				cout << "A ship can not be next to other one : " << endl;
				hata = 1;
			}
		}

		//alt taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[ship] + 2; i++)
		{
			if (userboard[row + 1][column + 1 - i] == 1)
			{
				cout << "A ship can not be next to other one : " << endl;
				hata = 1;
			}
		}
		// sol taraf degiyor mu 
		if (userboard[row][column - shipsizes[ship]] == 1)
		{
			cout << "A ship can not be next to other one : " << endl;
			hata = 1;
		}

		// sað taraf degiyor mu

		if (userboard[row][column + 1] == 1)
		{
			cout << "A ship can not be next to other one : " << endl;
			hata = 1;
		}

		break;
	case 4://right side 
		   //üst taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[ship] + 2; i++)
		{
			if (userboard[row - 1][column - 1 + i] == 1)
			{
				cout << "A ship can not be next to other one : " << endl;
				hata = 1;
			}
		}

		//alt taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[ship] + 2; i++)
		{
			if (userboard[row + 1][column - 1 + i] == 1)
			{
				cout << "A ship can not be next to other one : " << endl;
				hata = 1;
			}
		}
		// sað taraf degiyor mu 
		if (userboard[row][column + shipsizes[ship]] == 1)
		{
			cout << "A ship can not be next to other one : " << endl;
			hata = 1;
		}

		// sol taraf degiyor mu

		if (userboard[row][column - 1] == 1)
		{
			cout << "A ship can not be next to other one : " << endl;
			hata = 1;
		}

		break;
	default:
		break;
	}

	return hata;
}
int  allsettedcheck() {
	int hata = 0;
	for (size_t i = 0; i < 5; i++)
	{
		if (shipisselected[i] == 1)
		{
			hata = 1;
		}

	}
	return hata;
};
void setcompship() {
	switch (compdirection)
	{
	case 1: // up side 
		for (size_t i = 0; i < shipsizes[compship]; i++)
		{
			compboard[(comprow)-i][compcolumn] = 1;
		}
		break;
	case 2:// down side 
		for (size_t i = 0; i < shipsizes[compship]; i++)
		{
			compboard[(comprow)+i][compcolumn] = 1;
		}
		break;
	case 3://left side 

		for (size_t i = 0; i < shipsizes[compship]; i++)
		{
			compboard[comprow][compcolumn - i] = 1;
		}
		break;

	case 4:// right side 
		for (size_t i = 0; i < shipsizes[compship]; i++)
		{
			compboard[comprow][compcolumn + i] = 1;
		}
		break;
	default:
		break;
	}
};
void selectcompship() {
	compship++;

};
void generatecompcoor() {
	int comprowtemp, compcolumntemp, hata = 0;

	do
	{
		hata = 0;
		srand(time(NULL));
		comprowtemp = (rand() % 9) + 1;
		compcolumntemp = (rand() % 9) + 1;

		if (userboard[comprowtemp][compcolumntemp] != 0)
		{
			hata = 1;
		}
	} while (hata == 1);
	comprow = comprowtemp;
	compcolumn = compcolumntemp;
};
void generatecompdirect() {
	srand(time(NULL));
	compdirection = (rand() % 3) + 1;
};
int  compfixcheck() {

	int hata = 0;
	//sýgýyor mu diye kontrol 
	switch (compdirection)
	{
	case 1: // up side 
		if (shipsizes[compship] > comprow)
		{
			hata = 1;
		}




		break;
	case 2:// down side 
		if (shipsizes[compship] > 11 - comprow)
		{
			hata = 1;
		}

		break;
	case 3://left side 

		if (shipsizes[compship] > compcolumn)
		{
			hata = 1;
		}
		break;
	case 4:// right side 
		if (shipsizes[compship] > 11 - compcolumn)
		{
			hata = 1;
		}

		break;
	default:
		break;
	}
	return hata;

};
int  compcrosscheck() {
	int hata = 0;
	switch (compdirection)
	{
	case 1: // up side 
		for (size_t i = 0; i < shipsizes[compship]; i++)
		{
			if (compboard[(comprow)-i][compcolumn] == 1)
			{
				hata = 1;
			}

		}
		break;
	case 2:// down side 
		for (size_t i = 0; i < shipsizes[compship]; i++)
		{
			if (compboard[(comprow)+i][compcolumn] == 1)
			{
				hata = 1;
			}
		}
		break;
	case 3://left side 

		for (size_t i = 0; i < shipsizes[compship]; i++)
		{
			if (compboard[comprow][compcolumn - i] == 1)
			{
				hata = 1;
			}
		}
		break;
	case 4:
		for (size_t i = 0; i < shipsizes[compship]; i++)
		{
			if (compboard[comprow][compcolumn + i] == 1)
			{
				hata = 1;
			}
		}
		break;
	}
	return hata;
};
int  compnextcheck() {
	int hata = 0;
	switch (compdirection)
	{
	case 1: // up side
			// sol taraf degiyoru mu ? 
		for (size_t i = 0; i < shipsizes[compship] + 2; i++)
		{
			if (compboard[comprow + 1 - i][compcolumn - 1] == 1)
			{
				hata = 1;
			}
			// sað taraf deðiyor mu ? 
		}
		for (size_t i = 0; i < shipsizes[compship] + 2; i++)
		{
			if (compboard[comprow + 1 - i][compcolumn + 1] == 1)
			{
				hata = 1;
			}
		}
		// alt taraf deðiyor mu ?
		if (compboard[comprow - 1][compcolumn] == 1)
		{
			hata = 1;
		}
		//üst taraf degiyor mu ?
		if (compboard[comprow - shipsizes[compship]][compcolumn] == 1)
		{
			hata = 1;
		}
		break;
	case 2:// down side 
		   //sol taraf deðiyor mu 
		for (size_t i = 0; i < shipsizes[compship] + 2; i++)
		{
			if (compboard[comprow - 1 + i][compcolumn - 1] == 1)
			{
				hata = 1;
			}
		}
		//sag taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[compship] + 2; i++)
		{
			if (compboard[comprow - 1 + i][compcolumn + 1] == 1)
			{
				hata = 1;
			}
		}
		//alt taraf degiyor mu 
		if (compboard[comprow + shipsizes[compship]][compcolumn] == 1)
		{
			hata = 1;
		}
		// üst taraf degiyor ku 
		if (compboard[comprow - 1][compcolumn] == 1)
		{
			hata = 1;
		}
		break;
	case 3://left side 
		   //üst taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[compship] + 2; i++)
		{
			if (compboard[comprow - 1][compcolumn + 1 - i] == 1)
			{
				hata = 1;
			}
		}

		//alt taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[compship] + 2; i++)
		{
			if (compboard[comprow + 1][compcolumn + 1 - i] == 1)
			{
				hata = 1;
			}
		}
		// sol taraf degiyor mu 
		if (compboard[comprow][compcolumn - shipsizes[compship]] == 1)
		{
			hata = 1;
		}

		// sað taraf degiyor mu

		if (compboard[comprow][compcolumn + 1] == 1)
		{
			hata = 1;
		}

		break;
	case 4://right side 
		   //üst taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[compship] + 2; i++)
		{
			if (compboard[comprow - 1][compcolumn - 1 + i] == 1)
			{
				hata = 1;
			}
		}

		//alt taraf degiyor mu 
		for (size_t i = 0; i < shipsizes[compship] + 2; i++)
		{
			if (compboard[comprow + 1][compcolumn - 1 + i] == 1)
			{
				hata = 1;
			}
		}
		// sað taraf degiyor mu 
		if (compboard[comprow][compcolumn + shipsizes[compship]] == 1)
		{
			hata = 1;
		}

		// sol taraf degiyor mu

		if (compboard[comprow][compcolumn - 1] == 1)
		{
			hata = 1;
		}

		break;
	default:
		break;
	}

	return hata;
};
void showcompshootboard() {
	cout << "Computer Board " << endl;
	for (size_t i = 0; i < 11; i++)
	{
		cout << setw(2);
		for (size_t j = 0; j < 11; j++)
		{
			cout << compshootboard[i][j] << " ";
		}
		cout << endl;
	}
	cout << "0=empty area || 1=ships || 2=hitted ships || 4=missed shoots ||" << endl;
};
void selectshootcoor() {

	int usershootcolumntemp, usershootrowtemp, hata = 0;
	do
	{
		hata = 0;
		cout << endl << "Whic row do you wanna shoot ?";
		cin >> usershootrowtemp;
		cout << endl << "whic column do you wanna shoot ? ";
		cin >> usershootcolumntemp;
		if (usershootrowtemp <= 0 || usershootrowtemp > 10)
		{
			hata = 1;
			cout << "Corrdinates must be btw 1-10 !!" << endl;
		}

		if (usershootcolumntemp <= 0 || usershootcolumntemp > 10)
		{

			hata = 1;
			cout << "Coordinate must be btw 1-10 !!" << endl;
		}
		if (usershootedbefore[usershootrowtemp][usershootcolumntemp] == 1)
		{
			hata = 1;
			cout << "This area shooted before !!" << endl;
		}

	} while (hata == 1);

	usershootcolumn = usershootcolumntemp;
	usershootrow = usershootrowtemp;

};
void generatecompshootcoor() {
	int compshootcolumntemp, compshootrowtemp, hata = 0;
	do
	{
		hata = 0;
		srand(time(NULL));
		compshootrowtemp = (rand() % 10) + 1;
		compshootcolumntemp = (rand() % 10) + 1;
		if (compshootedbefore[compshootrowtemp][compshootcolumntemp] == 1)
		{
			hata = 1;
		}
	} while (hata == 1);

	compshootcolumn = compshootcolumntemp;
	compshootrow = compshootrowtemp;
};
int  usershoot() {
	int hit = 0;
	if (compboard[usershootrow][usershootcolumn] == 1)
	{
		hit = 1;
		compshootboard[usershootrow][usershootcolumn] = 2;
		usershootedbefore[usershootrow][usershootcolumn] = 1;
	}
	else if (compboard[usershootrow][usershootcolumn] == 0)
	{
		compshootboard[usershootrow][usershootcolumn] = 4;
		usershootedbefore[usershootrow][usershootcolumn] = 1;
	}
	return hit;
};
int  compshoot() {

	int hit = 0;
	if (userboard[compshootrow][compshootcolumn] == 1)
	{
		hit = 1;
		userboard[compshootrow][compshootcolumn] = 2;
		compshootedbefore[compshootrow][compshootcolumn] = 1;
	}
	else
	{
		userboard[compshootrow][compshootcolumn] = 4;
		compshootedbefore[compshootrow][compshootcolumn] = 1;
	}
	return hit;

};

