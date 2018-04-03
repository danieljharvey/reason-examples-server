let parseJSON = (string: string) : option(Js.Json.t) => Json.parse(string);

let fields = json : Entries.fields =>
  Json.Decode.{
    title: json |> field("title", string),
    description: json |> field("description", string),
    code: json |> field("code", string),
  };

let item = json : Entries.item =>
  Json.Decode.{fields: json |> field("fields", fields)};

let entries = (json: Js.Json.t) : Entries.entries =>
  Json.Decode.{
    total: json |> field("total", int),
    skip: json |> field("skip", int),
    limit: json |> field("limit", int),
    items: field("items", array(item), json),
  };

let parseEntries = (string: string) : option(Entries.entries) =>
  parseJSON(string) |> Helpful.optionMap(entries);