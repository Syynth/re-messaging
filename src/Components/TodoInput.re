let valueFromEvent = evt : string => (
                                       evt
                                       |> ReactEventRe.Form.target
                                       |> ReactDOMRe.domElementToObj
                                     )##value;

type inputState = string;
let component = ReasonReact.reducerComponent("TodoInput");
let make = (~onSubmit, _children) => {
  ...component,
  initialState: () => "",
  reducer: (newText, _text) => ReasonReact.Update(newText),
  render: self =>
    <div>
      <input
        _type="text"
        value=self.state
        onChange=(
          self.handle((evt, self) => evt |> valueFromEvent |> self.send)
        )
        onKeyDown=(
          evt =>
            if (ReactEventRe.Keyboard.key(evt) == "Enter") {
              onSubmit(self.state);
              (self.handle(((), self) => self.send("")))();
            }
        )
      />
      <button
        onClick=(
          _ev => {
            onSubmit(self.state);
            (self.handle(((), self) => self.send("")))();
          }
        )>
        (ReasonReact.string("Add something"))
      </button>
    </div>,
};