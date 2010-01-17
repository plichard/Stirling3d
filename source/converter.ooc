import utils/convert
use math

main: func {
	name := String new(32)
	printf(">")
	scanf("%s",name)
	printf("Converting %s to %s...\n",name + ".obj",name + ".s3d")
	objtoS3D(name + ".obj",name + ".s3d")
	printf("DONE\n")
}
