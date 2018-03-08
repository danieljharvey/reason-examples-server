[%raw "require('isomorphic-fetch')"];

Js.log("Let's fetch the content please");

let accessToken = "";

let spaceIdentifier = "";

let contentfulUrl =
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