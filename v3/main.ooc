import CApplication,CFactory,CProduct
import utils/convert

main: func() {
	
	
	objtoS3D("models/midres-notex-monkey.obj","models/midres-notex-monkey.s3d")
	//CRessourceManager new()
	CApplication get() run()
	
}
