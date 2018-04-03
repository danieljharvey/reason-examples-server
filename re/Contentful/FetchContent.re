[%raw "require('isomorphic-fetch')"];

Js.log("Let's fetch the content please");

let contentfulAPI = "https://cdn.contentful.com/";

let accessToken = LoadConfig.findArgument("accessToken", Node.Process.argv);

let spaceIdentifier = LoadConfig.findArgument("spaceID", Node.Process.argv);

let addCommand = (restCommand: string) : string =>
  String.length(restCommand) > 0 ? "/" ++ restCommand : "";

let contentfulUrl = (restCommand: string) =>
  contentfulAPI
  ++ "spaces/"
  ++ spaceIdentifier
  ++ addCommand(restCommand)
  ++ "?access_token="
  ++ accessToken;

let doQuery = (url: string) => {
  Js.log2("Query...", url);
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.text)
    |> then_(text => print_endline(text) |> resolve)
  );
};

let queryEntriesUrl = (contentType: string) =>
  contentfulAPI
  ++ "spaces/"
  ++ spaceIdentifier
  ++ "/entries?access_token="
  ++ accessToken
  ++ "&content_type="
  ++ contentType;