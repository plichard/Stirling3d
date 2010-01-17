all:
	ooc main.ooc -g -v -driver=sequence -o=levelEditor -sourcepath=source/

clean:
	rm -rfv ooc_tmp/ main
