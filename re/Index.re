/* starting point */
let main = () => {
  /*FetchContent.doQuery(FetchContent.contentfulUrl("content_types")) |> ignore; */
  let callback = string => {
    Js.log2("reply", string);
    let optEntries = Methods.parseEntries(string);
    switch (optEntries) {
    | Some(entries) => Array.iter(Js.log, entries.items)
    | _ => ()
    };
  };
  FetchContent.doQuery(FetchContent.queryEntriesUrl("method"), callback);
  ();
};

main();