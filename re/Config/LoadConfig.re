let arrayFind = (f, a) => {
  let list = Array.to_list(a);
  List.exists(f, list) ? Some(List.find(f, list)) : None;
};

let beforeChar = (char: char, string: string) : option(string) =>
  String.contains(string, char) ?
    Some(String.sub(string, 0, String.index(string, char))) : None;

let beforeCharEquals =
    (char: char, string: string, find: string)
    : option(string) =>
  switch (beforeChar(char, string)) {
  | Some(foundString) when foundString == find => Some(foundString)
  | _ => None
  };

let ending = (sub: string, full: string) : option(string) => {
  let subLength = String.length(sub);
  let fullLength = String.length(full);
  subLength < fullLength - 1 ?
    Some(
      String.sub(
        full,
        String.length(sub) + 1,
        String.length(full) - String.length(sub) - 1,
      ),
    ) :
    None;
};

let afterCharValue =
    (char: char, string: string, find: string)
    : option(string) =>
  switch (beforeCharEquals(char, string, find)) {
  | Some(foundString) => ending(foundString, string)
  | _ => None
  };

let optionOr = (default: 'a, option: option('a)) : 'a =>
  switch (option) {
  | Some(a) => a
  | None => default
  };

let isItThere = (char, string, find) : bool =>
  switch (beforeCharEquals(char, string, find)) {
  | None => false
  | _ => true
  };

let findArgument = (key: string, argv: array(string)) : string => {
  let found = arrayFind(str => isItThere('=', str, key), argv);
  switch (found) {
  | Some(foundStr) => optionOr("", afterCharValue('=', foundStr, key))
  | _ => ""
  };
};

let allSome = x =>
  switch (x) {
  | None => false
  | _ => true
  };