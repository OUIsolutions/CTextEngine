
from CTolkit import *


def main():
    OUTPUT = 'CTextEngine.h'
    STARTER  =f'CTextEngine/CTextEngineMain.h'
    amalgamated_code = get_amalgamated_code(STARTER)
    with open(OUTPUT,'w') as f:
        f.write(amalgamated_code)

if __name__ == '__main__':
    main()

