open Jest;

describe("arrayFind", () => {
  open Expect;
  let testArray = [|1, 2, 3, 4, 5|];
  test("to find the first matching item", () =>
    expect(LoadConfig.arrayFind(a => a > 3, testArray)) |> toEqual(Some(4))
  );
  test("to find that there is nothing", () =>
    expect(LoadConfig.arrayFind(a => a > 6, testArray)) |> toEqual(None)
  );
});

describe("beforeCharEquals", () => {
  open Expect;
  test("it finds the key", () =>
    expect(LoadConfig.beforeCharEquals('=', "horses=no", "horses"))
    |> toEqual(Some("horses"))
  );
  test("it finds no key", () =>
    expect(LoadConfig.beforeCharEquals('=', "horses=no", "dogs"))
    |> toEqual(None)
  );
});

describe("afterCharValue", () => {
  open Expect;
  test("it finds the value", () =>
    expect(LoadConfig.afterCharValue('=', "horses=no", "horses"))
    |> toEqual(Some("no"))
  );
  test("it finds no value", () =>
    expect(LoadConfig.afterCharValue('=', "horses=no", "dogs"))
    |> toEqual(None)
  );
});

describe("ending", () => {
  open Expect;
  test("Works as expected", () =>
    expect(LoadConfig.ending("chewing", "chewing=gum"))
    |> toEqual(Some("gum"))
  );
  test("Doesn't explode", () =>
    expect(LoadConfig.ending("chewingmsdfsdfsdf", "chewing=gum"))
    |> toEqual(None)
  );
});

describe("findArgument", () => {
  open Expect;
  let testArray = [|"horses=yeah", "dogs=what", "cheeses=pleases"|];
  test("Works as expected", () =>
    expect(LoadConfig.findArgument("horses", testArray))
    |> toEqual(Some("yeah"))
  );
  test("Doesn't explode", () =>
    expect(LoadConfig.findArgument("pauses", testArray)) |> toEqual(None)
  );
});