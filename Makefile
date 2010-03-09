all:
	rock main.ooc -g -vv -driver=sequence -o=levelEditor -sourcepath=source/ -editor=geany -slave

clean:
	rm -rfv ooc_tmp/ main
