open BsStorybook.Main;

let _module = [%bs.raw "module"];

let default = () => {
  let myStory =
    createStory(~title="My First Reason Story", ~decorators=[], ~_module, ());
  myStory.add("first chapter", () =>
    <TodoApp />
  );
};