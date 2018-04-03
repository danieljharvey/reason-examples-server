type fields = {
  title: string,
  description: string,
  code: string,
};

type item = {fields};

type entries = {
  total: int,
  skip: int,
  limit: int,
  items: array(item),
};