type item = {
  title: string,
  completed: bool,
};

type state = {
  items: list(item),
};

let component = ReasonReact.reducerComponent("TodoApp");

let make = (_) => {
  ...component,
  initialState: () => {
    items: [
      { title: "Write some things to do", completed: false },
    ],
  },
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: ({ state: { items } }) =>
    <div className="app">
      <div className="title">
        (ReasonReact.string("What do?"))
      </div>
      <div className="items">
        (ReasonReact.string("Nuthin'"))
      </div>
    </div>
};