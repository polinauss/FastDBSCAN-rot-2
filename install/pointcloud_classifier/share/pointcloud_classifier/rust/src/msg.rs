#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to pointcloud_classifier__msg__ClusterResult

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ClusterResult {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub type_name: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ClusterResult::default())
  }
}

impl rosidl_runtime_rs::Message for ClusterResult {
  type RmwMsg = super::msg::rmw::ClusterResult;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        type_name: msg.type_name.as_str().into(),
        type_code: msg.type_code,
        center_x: msg.center_x,
        center_y: msg.center_y,
        center_z: msg.center_z,
        num_points: msg.num_points,
        width: msg.width,
        height: msg.height,
        depth: msg.depth,
        density: msg.density,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        type_name: msg.type_name.as_str().into(),
      type_code: msg.type_code,
      center_x: msg.center_x,
      center_y: msg.center_y,
      center_z: msg.center_z,
      num_points: msg.num_points,
      width: msg.width,
      height: msg.height,
      depth: msg.depth,
      density: msg.density,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      type_name: msg.type_name.to_string(),
      type_code: msg.type_code,
      center_x: msg.center_x,
      center_y: msg.center_y,
      center_z: msg.center_z,
      num_points: msg.num_points,
      width: msg.width,
      height: msg.height,
      depth: msg.depth,
      density: msg.density,
    }
  }
}


// Corresponds to pointcloud_classifier__msg__ClusterResultArray

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ClusterResultArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub clusters: Vec<super::msg::ClusterResult>,

}



impl Default for ClusterResultArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ClusterResultArray::default())
  }
}

impl rosidl_runtime_rs::Message for ClusterResultArray {
  type RmwMsg = super::msg::rmw::ClusterResultArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        clusters: msg.clusters
          .into_iter()
          .map(|elem| super::msg::ClusterResult::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        clusters: msg.clusters
          .iter()
          .map(|elem| super::msg::ClusterResult::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      clusters: msg.clusters
          .into_iter()
          .map(super::msg::ClusterResult::from_rmw_message)
          .collect(),
    }
  }
}


