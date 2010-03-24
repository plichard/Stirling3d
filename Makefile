all:
	ooc main.ooc -g -v -driver=sequence -o=levelEditor -sourcepath=source/ -editor=geany

clean:
	rm -rfv ooc_tmp/ main
