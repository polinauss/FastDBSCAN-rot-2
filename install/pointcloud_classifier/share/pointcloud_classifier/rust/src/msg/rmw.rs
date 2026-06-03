#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "pointcloud_classifier__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pointcloud_classifier__msg__ClusterResult() -> *const std::ffi::c_void;
}

#[link(name = "pointcloud_classifier__rosidl_generator_c")]
extern "C" {
    fn pointcloud_classifier__msg__ClusterResult__init(msg: *mut ClusterResult) -> bool;
    fn pointcloud_classifier__msg__ClusterResult__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ClusterResult>, size: usize) -> bool;
    fn pointcloud_classifier__msg__ClusterResult__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ClusterResult>);
    fn pointcloud_classifier__msg__ClusterResult__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ClusterResult>, out_seq: *mut rosidl_runtime_rs::Sequence<ClusterResult>) -> bool;
}

// Corresponds to pointcloud_classifier__msg__ClusterResult
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ClusterResult {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub type_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub type_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_z: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub num_points: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub width: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub height: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub depth: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub density: f32,

}



impl Default for ClusterResult {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pointcloud_classifier__msg__ClusterResult__init(&mut msg as *mut _) {
        panic!("Call to pointcloud_classifier__msg__ClusterResult__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ClusterResult {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pointcloud_classifier__msg__ClusterResult__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pointcloud_classifier__msg__ClusterResult__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pointcloud_classifier__msg__ClusterResult__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ClusterResult {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ClusterResult where Self: Sized {
  const TYPE_NAME: &'static str = "pointcloud_classifier/msg/ClusterResult";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pointcloud_classifier__msg__ClusterResult() }
  }
}


#[link(name = "pointcloud_classifier__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pointcloud_classifier__msg__ClusterResultArray() -> *const std::ffi::c_void;
}

#[link(name = "pointcloud_classifier__rosidl_generator_c")]
extern "C" {
    fn pointcloud_classifier__msg__ClusterResultArray__init(msg: *mut ClusterResultArray) -> bool;
    fn pointcloud_classifier__msg__ClusterResultArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ClusterResultArray>, size: usize) -> bool;
    fn pointcloud_classifier__msg__ClusterResultArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ClusterResultArray>);
    fn pointcloud_classifier__msg__ClusterResultArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ClusterResultArray>, out_seq: *mut rosidl_runtime_rs::Sequence<ClusterResultArray>) -> bool;
}

// Corresponds to pointcloud_classifier__msg__ClusterResultArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ClusterResultArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub clusters: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ClusterResult>,

}



impl Default for ClusterResultArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pointcloud_classifier__msg__ClusterResultArray__init(&mut msg as *mut _) {
        panic!("Call to pointcloud_classifier__msg__ClusterResultArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ClusterResultArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pointcloud_classifier__msg__ClusterResultArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pointcloud_classifier__msg__ClusterResultArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pointcloud_classifier__msg__ClusterResultArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ClusterResultArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ClusterResultArray where Self: Sized {
  const TYPE_NAME: &'static str = "pointcloud_classifier/msg/ClusterResultArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pointcloud_classifier__msg__ClusterResultArray() }
  }
}


