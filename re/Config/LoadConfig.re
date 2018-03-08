/*

 external readFileAsUtf8Sync :
   string -> (_[@bs.as "utf8"]) ->
   string = "readFileSync"
 [@@bs.val] [@@bs.module "fs"]

 */
/*
 let findArgument = (key: string): Option(string) => {
     None
 }*/
let arrayFind = (f, a) => {
  let list = Array.to_list(a);
  List.exists(f, list) ? Some(List.find(f, list)) : None;
};

let array = [|1, 2, 3, 4, 5|];

let thing = arrayFind(a => a > 3, array);

let nowt = arrayFind(a => a > 6, array);
/*Node.Process.argv*/