/* starting point */
let main = () => {
  /*FetchContent.doQuery(FetchContent.contentfulUrl("")) |> ignore;*/
  /*FetchContent.doQuery(FetchContent.contentfulUrl("content_types")) |> ignore; */
  let callback = string => {
    let optEntries = DecodeJSON.parseEntries(string);
    switch (optEntries) {
    | Some(entries) => Array.iter(Js.log, entries.items)
    | _ => ()
    };
  };
  let jsonPromise =
    FetchContent.doQuery(FetchContent.queryEntriesUrl("method"), callback);
  ();
};

main();