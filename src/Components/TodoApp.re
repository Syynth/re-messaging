type todoState = {items: list(TodoItem.todoItem)};

type todoAction =
  | AddItem(string)
  | ToggleItem(int);

let newId = ref(0);

let newItem = title: TodoItem.todoItem => {
  newId := newId^ + 1;
  {id: newId^, title, completed: false};
};

let component = ReasonReact.reducerComponent("TodoApp");

let make = _ => {
  ...component,
  initialState: () => {
    items: [{id: 0, title: "Write some things to do", completed: false}],
  },
  reducer: (action, {items}) =>
    switch (action) {
    | AddItem(title) =>
      ReasonReact.Update({items: [newItem(title), ...items]})
    | ToggleItem(id) =>
      ReasonReact.Update({
        items:
          List.map(
            (item: TodoItem.todoItem) => {
              ...item,
              completed: id === item.id ? ! item.completed : item.completed,
            },
            items,
          ),
      })
    },
  render: ({send, state: {items}}) =>
    <div className="app">
      <div className="title"> (ReasonReact.string("What do?")) </div>
      <TodoInput onSubmit=(text => send(AddItem(text))) />
      <div className="items">
        (
          List.map(
            (item: TodoItem.todoItem) =>
              <TodoItem key=string_of_int(item.id) item onToggle=(() => send(ToggleItem(item.id))) />,
            items,
          )
          |> Array.of_list
          |> ReasonReact.array
        )
      </div>
      <div className="footer">
        (
          ReasonReact.string(
            "Number of items: " ++ string_of_int(List.length(items)),
          )
        )
      </div>
    </div>,
};