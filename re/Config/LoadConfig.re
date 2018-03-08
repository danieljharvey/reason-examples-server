/*

 external readFileAsUtf8Sync :
   string -> (_[@bs.as "utf8"]) ->
   string = "readFileSync"
 [@@bs.val] [@@bs.module "fs"]

 */

 let findArgument = (argv: array(string), key: string): Option(string) => {
     None
 }
let arrayFind = (f, a) => {
  let list = Array.to_list(a);
  List.exists(f, list) ? Some(List.find(f, list)) : None;
};