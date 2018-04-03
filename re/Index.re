/* starting point */
let main = () => {
  FetchContent.doQuery(FetchContent.contentfulUrl("")) |> ignore;
  FetchContent.doQuery(FetchContent.contentfulUrl("content_types")) |> ignore;
  FetchContent.doQuery(FetchContent.queryEntriesUrl("method")) |> ignore;
};

main();