import CApplication,CFactory,CProduct
import utils/convert

main: func() {
	
	
	objtoS3D("models/notex-cube.obj","models/notex-cube.s3d")
	//CRessourceManager new()
	CApplication get() run()
	
}
