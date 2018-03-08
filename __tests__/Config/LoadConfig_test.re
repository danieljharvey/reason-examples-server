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