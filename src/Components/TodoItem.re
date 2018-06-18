type todoItem = {
  id: int,
  title: string,
  completed: bool,
};

let component = ReasonReact.statelessComponent("TodoItem");
let make = (~item, ~onToggle, _children) => {
  ...component,
  render: self =>
    <div className="item" onClick=(_evt => onToggle())>
      <input
        _type="checkbox"
        checked=(Js.Boolean.to_js_boolean(item.completed))
      />
      (ReasonReact.string(item.title))
    </div>,
};