
function main()


    darwin.silverchain.generate({
        src = "src",
        tags = { "native_imports", "macros", "types","consts", "fdeclare", "fdefine" },
        implement_main = false,
        project_short_cut="CTextEngine",
    })

    if darwin.argv.one_of_args_exist("only_silverchain") then
        return 
    end 

    local MAX_CONNTENT = darwin.camalgamator.ONE_MB * 20
    local MAX_RECURSION = 100

    local lincense = "/* " .. darwin.dtw.load_file("LICENSE") .. " */ \n"

    local onefile = darwin.camalgamator.generate_amalgamation("src/one.c", MAX_CONNTENT, MAX_RECURSION)
    onefile = lincense .. onefile

    darwin.dtw.write_file("release/CTextEngineOne.c", onefile)

    local only_declare = darwin.camalgamator.generate_amalgamation("src/imports/imports.fdeclare.h", MAX_CONNTENT,
    MAX_RECURSION)
    only_declare = lincense .. only_declare
    darwin.dtw.write_file("release/CTextEngine.h", only_declare)



    local only_definition = darwin.camalgamator.generate_amalgamation_with_callback("src/imports/imports.fdefine.h",
        function(import, path)
            if darwin.dtw.ends_with(import, ".c") then
                return "include-once"
            end
            return "dont-include"
        end,
        MAX_CONNTENT,
        MAX_RECURSION
    )
    only_definition = '#include "CTextEngine.h"\n' .. only_definition

    only_definition = lincense .. only_definition

    darwin.dtw.write_file("release/CTextEngine.c", only_definition)

    os.execute("zip -r release/CTextEngine.zip src build")


end 