
import Build.CToolKit as ct
from Build.exemple_build import create_exemples
from Build.full_folder_zip import zip_folder


STARTER = 'CTextEngine/CTextEngineMain.h'
TEST_NAME  = 'CTextEngine.h'

OUTPUT_TEST = 'tests/CTextEngine.h'
OUTPUT = 'CTextEngine.h'
ZIP_NAME ='CTextEngine'


ct.generate_amalgamated_code(STARTER,OUTPUT_TEST)
test = ct.FolderTestPreset(folder='tests/main_test',side_effect_folder='tests/side_effect')
#test.generate_ouptut()
#test.start_test()
#create_exemples(TEST_NAME,OUTPUT)

ct.include_code_in_markdown('README.md',save_file=True)

ct.generate_amalgamated_code(STARTER,OUTPUT)


zip_folder(ZIP_NAME)