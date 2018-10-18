main : main.c
	gcc main.c -o main -I./Include  ./RELEASE/libmenu.so ./RELEASE/libstudent_operate.so ./RELEASE/libclass_operate.so
clean:
	cd ./MuduleA;make clean
	cd ./MuduleB;make clean
	cd ./MuduleC;make clean
	

