[%raw "require('isomorphic-fetch')"];

Js.log("Let's fetch the content please");

let accessToken = LoadConfig.findArgument("accessToken", Node.Process.argv);

let spaceIdentifier = LoadConfig.findArgument("spaceID", Node.Process.argv);

let contentfulUrl = (spaceIdentifier: string, accessToken: string) =>
  "https://cdn.contentful.com/spaces/"
  ++ spaceIdentifier
  ++ "?access_token="
  ++ accessToken;

let fetchContent = () =>
  Js.Promise.(
    Fetch.fetch(contentfulUrl)
    |> then_(Fetch.Response.text)
    |> then_(text => print_endline(text) |> resolve)
  );