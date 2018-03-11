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

let isItThere = (char, string, find) : bool =>
  switch (beforeCharEquals('=', string, find)) {
  | None => false
  | _ => true
  };

let findArgument = (key: string, argv: array(string)) : option(string) => {
  let found = arrayFind(str => isItThere('=', str, key), argv);
  switch (found) {
  | Some(foundStr) => afterCharValue('=', foundStr, key)
  | _ => None
  };
};

let sequenceFunc = (total, item) =>
  switch (total) {
  | Some(a) =>
    switch (item) {
    | Some(b) => Some(List.append([b], a))
    | None => None
    }
  | _ => None
  };

let sequence = (options: list(option('a))) : option(list('a)) =>
  List.fold_right(sequenceFunc, options, []);
/* pass in all data, and keys you want, passes back Some of all of them or None if any are missing */
/*let getOptionList = (keys: list(string), argv: array(string)) => {

  };*/