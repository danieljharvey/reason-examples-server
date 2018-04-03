let optionMap = (func: 'a => 'b, option: option('a)) : option('b) =>
  switch (option) {
  | Some(thing) => Some(func(thing))
  | None => None
  };