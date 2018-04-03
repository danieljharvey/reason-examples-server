type fields = {
  title: string,
  description: string,
  code: string,
  moduleID: array(string),
};

type item = {
  fields,
  id: string,
};

type entries = {
  total: int,
  skip: int,
  limit: int,
  items: array(item),
};

let sysID = json : string =>
  Json.Decode.field("id", Json.Decode.string, json);

let linkedModules = json : string =>
  Json.Decode.(json |> field("sys", sysID));

let fields = json : fields =>
  Json.Decode.{
    title: json |> field("title", string),
    description: json |> field("description", string),
    code: json |> field("code", string),
    moduleID: json |> field("module", array(linkedModules)),
  };

let item = json : item => {
  open Json.Decode;
  let fields = json |> field("fields", fields);
  let id = json |> field("sys", sysID);
  {fields, id};
};

let entries = (json: Js.Json.t) : entries =>
  Json.Decode.{
    total: json |> field("total", int),
    skip: json |> field("skip", int),
    limit: json |> field("limit", int),
    items: field("items", array(item), json),
  };

let parseEntries = (string: string) : option(entries) =>
  Json.parse(string) |> Helpful.optionMap(entries);